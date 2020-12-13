open Belt
type anchorId = string
@react.component
let make = (
  ~comments: array<(anchorId, CommentFragments.CommentDisplayData.t)>,
  ~focusedCommentId=?,
) => {
  let isFocused = commentId =>
    switch focusedCommentId {
    | Some(focusedId) => commentId === focusedId
    | None => false
    }
  comments->Array.length === 0
    ? React.null
    : <>
        <div className="title is-4"> {"Comments"->React.string} </div>
        {comments
        ->List.fromArray
        ->List.sort(((_, c1), (_, c2)) => Timestamp.compare(c2.createdAt, c1.createdAt))
        ->List.toArray
        ->Array.map(((anchorId, comment)) =>
          <CommentDisplay key=comment.id comment anchorId focused={isFocused(comment.id)} />
        )
        ->React.array}
      </>
}
