[@react.component]
let make = (~post: PostFragments.PostDisplayData.t) => {
  let contentStyle = ReactDOM.Style.make(~whiteSpace="pre-wrap", ());
  let authorName =
    <UserRef
      userData={
        post.author
        ->Belt.Option.map(user => {UserRef.id: user.id, name: user.name})
      }
    />;
  <>
    <div className="title is-1"> post.title->React.string </div>
    <span className="subtitle is-4">
      <span> "By "->React.string </span>
      authorName
    </span>
    <Timestamp.Display className="is-italic ml-2" of_={post.createdAt} />
    <p className="content mt-3" style=contentStyle>
      post.content->React.string
    </p>
  </>;
};
