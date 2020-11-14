module ApolloProvider = {
  [@react.component]
  let make = (~children) =>
    <ApolloClient.React.ApolloProvider client=GraphQlClient.instance>
      children
    </ApolloClient.React.ApolloProvider>;
};

type user = UserFragments.UserContextData.t;

[@react.component]
let make = () => {
  let pageComp = ReasonReactRouter.useUrl()->Route.fromUrl->Pages.fromRoute;
  let (activeUser: option(user), setActiveUser) = React.useState(() => None);

  <ApolloProvider>
    <UserContext.Provider value=activeUser>
      <PageFrame
        activeUser setActiveUser={user => setActiveUser(_ => Some(user))}>
        pageComp
      </PageFrame>
    </UserContext.Provider>
  </ApolloProvider>;
};
