open UserFragments;
open PostFragments;

[%graphql
  {|
query AuthorsQuery {
  authors {
    ...UserPreviewData
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
