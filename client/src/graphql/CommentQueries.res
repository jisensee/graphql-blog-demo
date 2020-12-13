open CommentFragments
%graphql(`
query PostCommentsQuery($postId: ID!) {
  post(id: $postId) {
    comments {
      ...CommentDisplayData
    }
  }
}
`)
