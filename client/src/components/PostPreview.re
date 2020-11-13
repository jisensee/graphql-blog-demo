[@react.component]
let make = (~post: PostFragments.PostPreviewData.t) => {
  let authorName =
    <UserRef
      userData={
        post.author
        ->Belt.Option.map(user => {UserRef.id: user.id, name: user.name})
      }
    />;

  <div className="box content">
    <Link to_={Route.Post(post.id)}>
      <p className="title is-3"> post.title->React.string </p>
    </Link>
    <p className="subtitle is-5">
      <span> "By "->React.string </span>
      authorName
    </p>
    <p className="has-text-weight-semibold"> post.abstract->React.string </p>
  </div>;
};
