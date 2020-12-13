type userData = {
  id: string,
  name: string,
}
@react.component
let make = (~userData) =>
  switch userData {
  | Some(data) => <Link to_=Route.User(data.id)> {data.name->React.string} </Link>
  | None => "[deleted]"->React.string
  }
