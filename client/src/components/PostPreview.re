[@react.component]
let make = (~title, ~author) => {
  let text = title ++ " - " ++ author;
  <p> text->React.string </p>;
};
