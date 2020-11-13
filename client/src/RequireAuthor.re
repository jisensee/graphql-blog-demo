[@react.component]
let make = (~children) => UserContext.useIsAuthor() ? children : React.null;
