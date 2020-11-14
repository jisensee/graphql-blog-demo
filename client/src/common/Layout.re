module PageTitle = {
  [@react.component]
  let make = (~children) => <p className="title is-2"> children </p>;
};

module PageSubTitle = {
  [@react.component]
  let make = (~children) => <p className="subtitle is-4"> children </p>;
};

module PageContent = {
  [@react.component]
  let make = (~children) =>
    <div className="content ml-3 py-3"> children </div>;
};
