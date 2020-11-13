module Title = {
  [@react.component]
  let make = (~children) => <p className="title is-1"> children </p>;
};

module SubTitle = {
  [@react.component]
  let make = (~children) => <p className="subtitle is-4"> children </p>;
};

module PageContent = {
  [@react.component]
  let make = (~children) =>
    <div className="content ml-3 py-3"> children </div>;
};
