open Belt;

let useUsers = () =>
  switch (UserQueries.UsersQuery.use()) {
  | {data: Some({users})} => Some(users)
  | _ => None
  };
[@react.component]
let make = (~children, ~activeUser, ~setActiveUser) => {
  let users = useUsers();
  React.useEffect1(
    () => {
      users->Option.flatMap(Array.get(_, 0))->Option.forEach(setActiveUser);
      None;
    },
    [|users|],
  );

  let userSelect =
    switch (users, activeUser) {
    | (Some(users), Some(activeUser)) =>
      Some(<UserSelect users activeUser onUserChange=setActiveUser />)
    | _ => None
    };

  <>
    <Navbar userSelect />
    <div className="content ml-3 py-3"> children </div>
  </>;
};
