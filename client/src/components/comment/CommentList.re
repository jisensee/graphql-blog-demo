[@react.component]
let make = (~comments: array(CommentFragments.CommentDisplayData.t)) => {
  comments->Belt.Array.length === 0
    ? React.null
    : <>
        <p className="title is-4"> "Comments"->React.string </p>
        {comments
         ->Belt.Array.map(comment =>
             <CommentDisplay key={comment.id} comment />
           )
         ->React.array}
      </>;
};
