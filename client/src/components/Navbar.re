[@react.component]
let make = (~userSelect) => {
  let (expanded, setExpanded) = React.useState(() => false);
  let toggleBurger = _ => setExpanded(e => !e);
  let hideBurger = () => setExpanded(_ => false);
  let navbarMenuClass = "navbar-menu" ++ (expanded ? " is-active" : "");
  let user = UserContext.use();
  let burgerClass =
    "navbar navbar-burger has-background-light"
    ++ (expanded ? " is-active" : "");
  let linkItem = (route, icon, text) =>
    <Link to_=route className="navbar-item mx-2" onClick=hideBurger>
      <Icon icon> text </Icon>
    </Link>;
  <nav className="navbar is-fixed-top has-background-light" role="navigation">
    <div className="navbar-brand">
      {linkItem(Route.Posts, "home", "Posts"->React.string)}
      <div className="navbar-item is-pulled-right">
        {userSelect->Belt.Option.getWithDefault(React.null)}
      </div>
      <a role="button" className=burgerClass onClick=toggleBurger>
        <span ariaHidden=true />
        <span ariaHidden=true />
        <span ariaHidden=true />
      </a>
    </div>
    <div className=navbarMenuClass>
      <div className="navbar-start">
        <RequireAuthor>
          {linkItem(Route.AddPost, "edit", "New post"->React.string)}
        </RequireAuthor>
        {linkItem(Route.Authors, "users", "Authors"->React.string)}
        {switch (user) {
         | None => React.null
         | Some({id}) =>
           linkItem(Route.User(id), "user", "My profile"->React.string)
         }}
      </div>
    </div>
  </nav>;
};
