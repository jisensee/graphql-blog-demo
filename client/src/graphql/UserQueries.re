open UserFragments;
open PostFragments;
open CommentFragments;

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
    comments {
      ...CommentPreviewData
    }
    ...UserDisplayData
  }
}
|};
  {inline: true}
];
