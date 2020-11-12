

import * as ApolloClient from "reason-apollo-client/src/ApolloClient.bs.js";
import * as ApolloClient__ApolloClient from "reason-apollo-client/src/@apollo/client/ApolloClient__ApolloClient.bs.js";
import * as ApolloClient__Cache_InMemory_InMemoryCache from "reason-apollo-client/src/@apollo/client/cache/inmemory/ApolloClient__Cache_InMemory_InMemoryCache.bs.js";

var instance = ApolloClient.make((function (param) {
        return "http://localhost:5000/graphql";
      }), undefined, undefined, undefined, ApolloClient__Cache_InMemory_InMemoryCache.make(undefined, undefined, undefined, undefined, undefined, undefined), undefined, undefined, true, undefined, ApolloClient__ApolloClient.DefaultOptions.make(ApolloClient__ApolloClient.DefaultMutateOptions.make(undefined, undefined, true, /* All */2, undefined, undefined), ApolloClient__ApolloClient.DefaultQueryOptions.make(/* NetworkOnly */2, /* All */2, undefined, undefined), undefined, undefined), undefined, undefined, undefined, undefined, undefined, undefined, undefined);

export {
  instance ,
  
}
/* instance Not a pure module */
