module Comments = {
  module CommentsQuery = CommentQueries.PostCommentsQuery;
  [@react.component]
  let make = (~postId, ~focusedCommentId=?) => {
    let result = CommentsQuery.makeVariables(~postId, ())->CommentsQuery.use;
    switch (result) {
    | {data: Some({post: Some({comments})})} =>
      <CommentList
        comments={comments->Belt.Array.map(c => (c.id, c))}
        ?focusedCommentId
      />
    | _ => React.null
    };
  };
};

module PostQuery = PostQueries.PostDisplayQuery;
[@react.component]
let make = (~postId, ~focusedCommentId) => {
  let result = PostQuery.makeVariables(~postId, ())->PostQuery.use;
  let (commentFormVisible, setCommentFormVisible) =
    React.useState(() => false);
  let toggleCommentFormVisible = _ => setCommentFormVisible(prev => !prev);

  switch (result) {
  | {loading: true} => "Loading..."->React.string
  | {data: Some({post: maybePost})} =>
    switch (maybePost) {
    | Some(post) =>
      <>
        <PostDisplay post />
        <Button
          className="mb-3"
          onClick=toggleCommentFormVisible
          style=Button.Info
          icon="comment">
          "Comment"->React.string
        </Button>
        {commentFormVisible ? <AddCommentForm postId={post.id} /> : React.null}
        <br />
        <Comments postId={post.id} ?focusedCommentId />
      </>
    | None => "That post does not exist :("->React.string
    }
  | {error: Some(_)}
  | _ => "Error :("->React.string
  };
};
