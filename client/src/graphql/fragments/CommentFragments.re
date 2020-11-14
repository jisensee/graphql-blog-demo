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
|}
];
