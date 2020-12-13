[%graphql
  {|
mutation AddPostMutation($authorId: ID!, $title: String!, $content: String!) {
  addPost(authorId: $authorId, title: $title, content: $content) {
    id
  }
}
mutation AddCommentMutation($authorId: ID!, $postId: ID!, $content: String!) {
  addComment(authorId: $authorId, postId: $postId, content: $content){
    id
  }
}
mutation LikePostMutation($postId: ID!, $userId: ID!) {
  likePost(postId: $postId, userId: $userId)
}
|}
];
