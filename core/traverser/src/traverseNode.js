import traverseNodeList from './traverseNodeList'
import createPath from './createPath'

export default function traverseNode(node, visitor, parentPath) {
  const methods = visitor[node.type]

  const nodePath = createPath(node, parentPath, parentPath.context)

  if (methods && methods.enter) {
    methods.enter(nodePath)
  }

  switch (node.type) {
    case 'File':
    case 'Style':
    case 'Variant':
      traverseNodeList(node.body, visitor, nodePath)
      break

    case 'FunctionExpression':
      traverseNodeList(node.params, visitor, nodePath)
      break

    case 'Conditional':
      !node.boolean && traverseNode(node.value, visitor, nodePath)
      traverseNode(node.property, visitor, nodePath)
      traverseNodeList(node.body, visitor, nodePath)
      break

    case 'Declaration':
      traverseNode(node.value, visitor, nodePath)
      break

    case 'Variable':
    case 'Float':
    case 'Integer':
    case 'Identifier':
    case 'String':
      break

    default:
      throw new TypeError(`Unkown Type ${node.type}`)
  }

  if (methods && methods.exit) {
    methods.exit(nodePath)
  }
}
