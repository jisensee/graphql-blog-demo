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

fragment AuthorPreviewData on User {
  id
  name
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
