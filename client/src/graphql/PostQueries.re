open PostFragments;
open CommentFragments;

[%graphql
  {|
query PostPreviewsQuery {
  posts {
    ...PostPreviewData
  }
}

query PostDisplayQuery($postId: ID!) {
  post(id: $postId) {
    ...PostDisplayData
  }
}
  |};
  {inline: true}
];
