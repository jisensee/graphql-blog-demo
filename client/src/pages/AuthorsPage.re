[@react.component]
let make = () => {
  let authors =
    switch (UserQueries.AuthorsQuery.use()) {
    | {data: Some({authors})} => authors
    | _ => [||]
    };

  <>
    <div className="title is-1"> "Authors"->React.string </div>
    {authors
     ->Belt.Array.map(author => <UserPreview key={author.id} user=author />)
     ->React.array}
  </>;
};
