open UserFragments;
open CommentFragments;

[%graphql
  {|
  fragment PostPreviewData on Post {
    id
    title
    abstract
    author {
      ...PostPreviewAuthorData
    }
  }

  fragment PostDisplayData on Post {
    title
    content
    author {
      ...PostDisplayAuthorData
    }
    comments {
      ...CommentDisplayData
    }
  }
|};
  {inline: true}
];
