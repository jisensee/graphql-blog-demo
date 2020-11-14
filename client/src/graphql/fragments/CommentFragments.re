open UserFragments;

[%graphql
  {|
fragment CommentDisplayData on Comment {
  id
  content
  author {
    ...CommentAuthorData
  }
}
|}
];
