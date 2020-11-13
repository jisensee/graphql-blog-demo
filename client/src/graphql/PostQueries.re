open PostFragments;

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
