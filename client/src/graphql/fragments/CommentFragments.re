open UserFragments;

[%graphql
  {|
fragment CommentDisplayData on Comment {
  content
  author {
    ...CommentAuthorData
  }
}
|}
];
