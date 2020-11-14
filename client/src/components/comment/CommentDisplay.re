[@react.component]
let make = (~comment: CommentFragments.CommentDisplayData.t) => {
  let userData =
    switch (comment.author) {
    | Some({id, username}) => Some({UserRef.id, name: "@" ++ username})
    | None => None
    };

  <div className="box">
    <p className="title is-5"> <UserRef userData /> </p>
    <p> comment.content->React.string </p>
  </div>;
};
