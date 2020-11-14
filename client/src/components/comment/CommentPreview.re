[@react.component]
let make = (~comment: CommentFragments.CommentPreviewData.t) => {
  let commentContent =
    <>
      <div className="title is-5"> comment.content->React.string </div>
      "At "->React.string
      <Timestamp.Display className="is-italic" of_={comment.createdAt} />
    </>;
  switch (comment.post) {
  | Some(post) =>
    <Link className="box" to_={Route.Post(post.id, Some(comment.id))}>
      commentContent
      " on "->React.string
      <span className="has-text-weight-bold"> post.title->React.string </span>
    </Link>
  | None => <div className="box"> commentContent </div>
  };
};
