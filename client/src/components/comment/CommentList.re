open Belt;

[@react.component]
let make = (~comments: array(CommentFragments.CommentDisplayData.t)) => {
  comments->Belt.Array.length === 0
    ? React.null
    : <>
        <p className="title is-4"> "Comments"->React.string </p>
        {comments
         ->List.fromArray
         ->List.sort((c1, c2) =>
             Timestamp.compare(c2.createdAt, c1.createdAt)
           )
         ->List.toArray
         ->Array.map(comment => <CommentDisplay key={comment.id} comment />)
         ->React.array}
      </>;
};
