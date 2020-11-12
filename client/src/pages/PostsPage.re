open Belt;

[%graphql
  {|
        query AllPostsQuery {
          posts {
            id
            title
            author {
              name
            }
          }
        }
|}
];

module PostList = {
  [@react.component]
  let make = (~posts: array(AllPostsQuery.AllPostsQuery_inner.t_posts)) =>
    posts
    ->Array.map(p =>
        <PostPreview
          key={p.id}
          title={p.title}
          author={p.author->Option.mapWithDefault("", a => a.name)}
        />
      )
    ->React.array;
};

[@react.component]
let make = () =>
  switch (AllPostsQuery.use()) {
  | {loading: true} => "Loading..."->React.string
  | {data: Some({posts})} => <PostList posts />
  // | {data: Some({posts})} => <p> "Posts"->React.string </p>
  | {error: Some(_error)} => "Error :("->React.string
  | _ => "lul"->React.string
  };
