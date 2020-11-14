open Belt;

[@react.component]
let make = (~comments: array(CommentFragments.CommentPreviewData.t)) =>
  comments->Array.length === 0
    ? React.null
    : <>
        <div className="title is-4"> "Comments"->React.string </div>
        {comments
         ->List.fromArray
         ->List.sort((c1, c2) =>
             Timestamp.compare(c2.createdAt, c1.createdAt)
           )
         ->List.toArray
         ->Array.map(comment => <CommentPreview key={comment.id} comment />)
         ->React.array}
      </>;
