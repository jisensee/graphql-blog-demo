let fromRoute = x =>
  switch x {
  | Route.Posts => <PostsPage />
  | Route.Post(postId, focusedCommentId) => <PostPage postId focusedCommentId />
  | Route.AddPost => <AddPostPage />
  | Route.Authors => <AuthorsPage />
  | Route.User(userId) => <UserPage userId />
  | Route.NotFound => <p> {"Nothing here :("->React.string} </p>
  }
