open UserFragments;
open PostFragments;

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
query UserQuery($userId: ID!) {
  user(id: $userId) {
    posts {
      ...PostPreviewData
    }
    ...UserDisplayData
  }
}
|};
  {inline: true}
];
