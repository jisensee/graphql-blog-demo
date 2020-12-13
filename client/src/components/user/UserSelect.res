open Belt

type userData = UserFragments.UserContextData.t

@react.component
let make = (~users: array<userData>, ~activeUser: userData, ~onUserChange) => {
  let onChange = event => {
    let selectedKey = (event->ReactEvent.Form.currentTarget)["value"]
    users->Array.getBy(user => user.id == selectedKey)->Option.forEach(onUserChange)
  }

  let selectClassName = activeUser.isAuthor ? "has-text-weight-bold" : ""
  <div className="select">
    <select className=selectClassName value=activeUser.id onChange>
      {users
      ->Belt.Array.map(user => {
        let className = user.isAuthor ? "has-text-weight-bold" : ""

        <option className key=user.id value=user.id> {user.name->React.string} </option>
      })
      ->React.array}
    </select>
  </div>
}
