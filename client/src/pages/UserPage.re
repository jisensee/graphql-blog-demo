module Query = UserQueries.UserQuery;

[@react.component]
let make = (~userId: string) => {
  let vars = Query.makeVariables(~userId, ());
  switch (Query.use(vars)) {
  | {data: Some({user: maybeUser})} =>
    switch (maybeUser) {
    | Some({userDisplayData: user, posts}) =>
      <>
        <Layout.PageTitle>
          {(user.name ++ " (@" ++ user.username ++ ")")->React.string}
        </Layout.PageTitle>
        {user.bio
         ->Belt.Option.mapWithDefault(React.null, bio =>
             <div className="box is-italic"> bio->React.string </div>
           )}
        {user.isAuthor && posts->Belt.Array.length > 0
           ? <>
               <p className="title is-3"> "Posts"->React.string </p>
               <PostPreviewList posts />
             </>
           : React.null}
      </>
    | None => <p> "That user does not exist :("->React.string </p>
    }
  | _ => React.null
  };
};
