

import * as React from "react";
import * as App$Client from "./App.bs.js";
import * as ReactDOMRe from "reason-react/src/legacy/ReactDOMRe.bs.js";

((import('@fortawesome/fontawesome-free/css/all.css')));

((import('bulma/css/bulma.css')));

ReactDOMRe.renderToElementWithId(React.createElement(App$Client.make, {}), "root");

export {
  
}
/*  Not a pure module */
