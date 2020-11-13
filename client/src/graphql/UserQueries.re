open UserFragments;

[%graphql
  {|
query AuthorsQuery {
  authors {
    ...AuthorPreviewData
  }
}
query UsersQuery {
  users {
    ...UserContextData
  }
}
|};
  {inline: true}
];
