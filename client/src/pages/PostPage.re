open PostQueries;

[@react.component]
let make = (~postId: string) => {
  let vars =
    PostDisplayQuery.PostDisplayQuery_inner.makeVariables(~postId, ());
  switch (PostDisplayQuery.use(vars)) {
  | {loading: true} => "Loading..."->React.string
  | {data: Some({post: maybePost})} =>
    switch (maybePost) {
    | Some(post) =>
      <> <PostDisplay post /> <CommentList comments={post.comments} /> </>
    | None => "That post does not exist :("->React.string
    }
  | {error: Some(_)}
  | _ => "Error :("->React.string
  };
};
