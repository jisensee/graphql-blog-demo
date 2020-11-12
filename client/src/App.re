let getPage =
  fun
  | [""] => <PostsPage />
  | _ => <p> "Nothing here :("->React.string </p>;

module ApolloProvider = {
  [@react.component]
  let make = (~children) =>
    <ApolloClient.React.ApolloProvider client=GraphQlClient.instance>
      children
    </ApolloClient.React.ApolloProvider>;
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  <ApolloProvider> url.path->getPage </ApolloProvider>;
};
