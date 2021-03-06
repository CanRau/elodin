open Utils;
open Next;

module NavigationLink = {
  [@react.component]
  let make = (~disabled=false, ~href, ~children) => {
    let css = ReactFela.useFela1();
    let router = Router.useRouter();
    let isActive = router##pathname === href;
    let status = isActive ? Some(NavigationStyle.Active) : None;

    <div className={css(NavigationStyle.navigationItem())}>
      {disabled
         ? <span className={css(NavigationStyle.navigationItemDisabled())}>
             {children |> s}
           </span>
         : <Link href>
             <a
               className={css(
                 NavigationStyle.navigationItemText(~status?, ()),
               )}>
               {children |> s}
             </a>
           </Link>}
    </div>;
  };
};

module NavigationGroup = {
  [@react.component]
  let make = (~text, ~children=?) => {
    let css = ReactFela.useFela1();
    <div className={css(NavigationStyle.navigationItem())}>
      <span className={css(NavigationStyle.navigationGroupText())}>
        {text |> s}
      </span>
      {resolveOption(
         children,
         c =>
           <div className={css(NavigationStyle.navigationInnerContainer())}>
             c
           </div>,
         React.null,
       )}
    </div>;
  };
};

module NavigationContent = {
  [@react.component]
  let make = () =>
    <>
      <NavigationGroup text="Intro">
        <NavigationLink href="/docs/intro/what-why">
          "What & Why"
        </NavigationLink>
      </NavigationGroup>
      <NavigationGroup text="Setup">
        <NavigationLink href="/docs/setup/installation">
          "Installation"
        </NavigationLink>
        <NavigationLink href="/docs/setup/getting-started">
          "Getting Started"
        </NavigationLink>
        <NavigationLink href="/docs/setup/configuration">
          "Configuration"
        </NavigationLink>
        <NavigationLink href="/docs/setup/editor-plugins">
          "Editor Plugins"
        </NavigationLink>
        <NavigationLink href="/docs/setup/ecosystem">
          "Ecosystem"
        </NavigationLink>
      </NavigationGroup>
      <NavigationGroup text="Language">
        <NavigationLink href="/docs/language/styles">
          "Styles"
        </NavigationLink>
        <NavigationLink href="/docs/language/Primitives">
          "Primitives"
        </NavigationLink>
        <NavigationLink href="/docs/language/variables">
          "Variables"
        </NavigationLink>
        <NavigationLink href="/docs/language/variants">
          "Variants"
        </NavigationLink>
        <NavigationLink href="/docs/language/conditionals">
          "Conditionals"
        </NavigationLink>
        <NavigationLink href="/docs/language/comments">
          "Comments"
        </NavigationLink>
        <NavigationLink href="/docs/language/functions">
          "Functions"
        </NavigationLink>
      </NavigationGroup>
      <NavigationGroup text="Targets">
        <NavigationLink href="/docs/targets/overview">
          "Overview"
        </NavigationLink>
        <NavigationGroup text="JavaScript">
          <NavigationLink href="/docs/targets/javascript/css-in-js">
            "CSS in JS"
          </NavigationLink>
          <div style={ReactDOMRe.Style.make(~paddingLeft="15px", ())}>
            <NavigationLink href="/docs/targets/javascript/css-in-js/fela">
              "fela"
            </NavigationLink>
            <NavigationLink href="/docs/targets/javascript/css-in-js/glamor">
              "glamor"
            </NavigationLink>
          </div>
          <NavigationLink href="/docs/targets/javascript/react-native">
            "React Native"
          </NavigationLink>
          <NavigationLink
            href="/docs/targets/javascript/vanilla" disabled=true>
            "Vanilla"
          </NavigationLink>
        </NavigationGroup>
        <NavigationGroup text="ReasonML">
          <NavigationLink href="/docs/targets/reasonml/css-in-reason">
            "CSS in Reason"
          </NavigationLink>
          <div style={ReactDOMRe.Style.make(~paddingLeft="15px", ())}>
            <NavigationLink
              href="/docs/targets/reasonml/css-in-reason/reason-fela">
              "reason-fela"
            </NavigationLink>
            <NavigationLink href="/docs/targets/reasonml/css-in-reason/bs-css">
              "bs-css"
            </NavigationLink>
          </div>
          <NavigationLink
            href="/docs/targets/reasonml/react-native" disabled=true>
            "React Native"
          </NavigationLink>
        </NavigationGroup>
      </NavigationGroup>
      <NavigationGroup text="Plugins">
        <NavigationLink href="/docs/plugins/color"> "Color" </NavigationLink>
        <NavigationLink href="/docs/plugins/replace-variable">
          "Replace Variable"
        </NavigationLink>
        <NavigationLink href="/docs/plugins/rename-variable">
          "Rename Variable"
        </NavigationLink>
      </NavigationGroup>
      <NavigationGroup text="Advanced">
        <NavigationLink href="/docs/advanced/under-the-hood" disabled=true>
          "Under The Hood"
        </NavigationLink>
        <NavigationLink href="/docs/advanced/specification">
          "Specification"
        </NavigationLink>
      </NavigationGroup>
      <NavigationGroup text="API Reference">
        <NavigationLink href="/docs/api/cli"> "CLI" </NavigationLink>
        <NavigationLink href="/docs/api/core"> "Core" </NavigationLink>
        <NavigationLink href="/docs/api/parser"> "Parser" </NavigationLink>
        <NavigationLink href="/docs/api/traverser">
          "Traverser"
        </NavigationLink>
        <NavigationLink href="/docs/api/format"> "Formatter" </NavigationLink>
        <NavigationLink href="/docs/api/types" disabled=true>
          "Types"
        </NavigationLink>
      </NavigationGroup>
      <NavigationGroup text="Extra">
        <NavigationLink href="/docs/extra/examples">
          "Examples"
        </NavigationLink>
        <NavigationLink href="/docs/extra/faq"> "FAQ" </NavigationLink>
      </NavigationGroup>
    </>;
};

[@react.component]
let make = () => {
  let css = ReactFela.useFela1();
  <nav className={css(NavigationStyle.navigation())}>
    <NavigationContent />
  </nav>;
};