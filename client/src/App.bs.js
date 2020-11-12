

import * as React from "react";
import * as Client from "@apollo/client";
import * as PostsPage$Client from "./pages/PostsPage.bs.js";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.bs.js";
import * as GraphQlClient$Client from "./GraphQlClient.bs.js";

function getPage(param) {
  if (param && param.hd === "" && !param.tl) {
    return React.createElement(PostsPage$Client.make, {});
  }
  return React.createElement("p", undefined, "Nothing here :(");
}

function App$ApolloProvider(Props) {
  var children = Props.children;
  return React.createElement(Client.ApolloProvider, {
              client: GraphQlClient$Client.instance,
              children: children
            });
}

var ApolloProvider = {
  make: App$ApolloProvider
};

function App(Props) {
  var url = ReasonReactRouter.useUrl(undefined, undefined);
  return React.createElement(App$ApolloProvider, {
              children: getPage(url.path)
            });
}

var make = App;

export {
  getPage ,
  ApolloProvider ,
  make ,
  
}
/* react Not a pure module */
