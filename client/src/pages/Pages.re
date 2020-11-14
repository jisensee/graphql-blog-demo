let fromRoute =
  fun
  | Route.Posts => <PostsPage />
  | Route.Post(postId) => <PostPage postId />
  | Route.AddPost => <AddPostPage />
  | Route.Authors => <AuthorsPage />
  | Route.User(userId) => <UserPage userId />
  | Route.NotFound => <p> "Nothing here :("->React.string </p>;
