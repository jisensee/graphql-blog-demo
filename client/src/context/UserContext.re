type userContextData = UserFragments.UserContextData.t;

type contextValue = option(userContextData);
let userContext = React.createContext(None: contextValue);

let useUser = () => React.useContext(userContext);

let useIsAuthor = () =>
  switch (useUser()) {
  | Some(user) => user.isAuthor
  | None => false
  };

module Provider = {
  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
  let make = React.Context.provider(userContext);
};
