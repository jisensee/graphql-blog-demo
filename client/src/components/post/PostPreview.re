[@react.component]
let make = (~post: PostFragments.PostPreviewData.t) => {
  let authorName =
    <UserRef
      userData={
        post.author
        ->Belt.Option.map(user => {UserRef.id: user.id, name: user.name})
      }
    />;

  <div className="box">
    <Link to_={Route.Post(post.id, None)}>
      <p className="title is-3"> post.title->React.string </p>
    </Link>
    <span className="subtitle is-5">
      <span> "By "->React.string </span>
      authorName
    </span>
    <Timestamp.Display className="is-italic ml-3" of_={post.createdAt} />
    <p className="has-text-weight-semibold mt-1">
      post.abstract->React.string
    </p>
  </div>;
};
