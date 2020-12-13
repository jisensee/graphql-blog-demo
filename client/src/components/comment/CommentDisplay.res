@react.component
let make = (~comment: CommentFragments.CommentDisplayData.t, ~anchorId, ~focused=false) => {
  let userData = switch comment.author {
  | Some({id, username}) => Some({UserRef.id: id, name: "@" ++ username})
  | None => None
  }
  let style = {
    open ReactDOM.Style
    focused ? make(~border="1px solid blue", ()) : make()
  }

  <div id=anchorId style className="box">
    <span className="title is-5"> <UserRef userData /> </span>
    <Timestamp.Display className="is-italic ml-2" of_=comment.createdAt />
    <p> {comment.content->React.string} </p>
  </div>
}
