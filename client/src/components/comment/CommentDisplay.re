[@react.component]
let make = (~comment: CommentFragments.CommentDisplayData.t) => {
  let userData =
    switch (comment.author) {
    | Some({id, username}) => Some({UserRef.id, name: "@" ++ username})
    | None => None
    };

  <div className="box">
    <span className="title is-5"> <UserRef userData /> </span>
    <Timestamp.Display className="is-italic ml-2" of_={comment.createdAt} />
    <p> comment.content->React.string </p>
  </div>;
};
