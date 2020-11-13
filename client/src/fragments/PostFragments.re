open UserFragments;

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
  }

|};
  {inline: true}
];
