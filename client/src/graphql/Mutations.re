[%graphql
  {|
mutation AddPostMutation($authorId: ID!, $title: String!, $content: String!) {
  addPost(authorId: $authorId, title: $title, content: $content) {
    id
  }
}
|}
];
