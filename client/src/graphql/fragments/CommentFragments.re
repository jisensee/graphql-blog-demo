open UserFragments;

[%graphql
  {|
fragment CommentDisplayData on Comment {
  id
  content
  createdAt
  author {
    ...CommentAuthorData
  }
}

fragment CommentPreviewData on Comment {
  id
  content
  createdAt
  post {
    id
    title
  }
}
|};
  {inline: true}
];
