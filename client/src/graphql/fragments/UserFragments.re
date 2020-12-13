[%graphql
  {|
fragment PostDisplayAuthorData on User {
  id
  name
  username
}

fragment PostPreviewAuthorData on User {
  id
  name
}

fragment CommentAuthorData on User {
  id
  username
}

fragment UserContextData on User {
  id
  name
  isAuthor
}

fragment UserPreviewData on User {
  id
  name
  bio
  postCount
}

fragment UserDisplayData on User {
  name
  username
  isAuthor
  bio
}
|};
  {inline: true}
];
