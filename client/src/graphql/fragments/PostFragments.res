open UserFragments

%graphql(
  `
  fragment PostPreviewData on Post {
    id
    title
    abstract
    createdAt
    author {
      ...PostPreviewAuthorData
    }
  }

  fragment PostDisplayData on Post {
    id
    title
    content
    createdAt
    likes
    author {
      ...PostDisplayAuthorData
    }
  }
`
  {inline: true}
)
