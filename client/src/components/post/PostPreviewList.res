@react.component
let make = (~posts: array<PostFragments.PostPreviewData.t>) => {
  let isAuthor = UserContext.useIsAuthor()
  posts->Belt.Array.length === 0
    ? <p>
        <span> {"No posts yet :( "->React.string} </span>
        {isAuthor ? <Link to_=Route.AddPost> {"Go write one!"->React.string} </Link> : React.null}
      </p>
    : posts->Belt.Array.map(post => <PostPreview key=post.id post />)->React.array
}
