let getPage =
  fun
  | Route.Posts => <PostsPage />
  | Route.Post(postId) => <PostPage postId />
  | Route.AddPost => <AddPostPage />
  | Route.Authors => <AuthorsPage />
  | Route.NotFound => <p> "Nothing here :("->React.string </p>;

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
  let url = ReasonReactRouter.useUrl();
  let pageComp = url.path->Route.fromPath->getPage;
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
