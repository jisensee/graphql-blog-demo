

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as PostPreview$Client from "../components/PostPreview.bs.js";
import * as ApolloClient__React_Hooks_UseQuery from "reason-apollo-client/src/@apollo/client/react/hooks/ApolloClient__React_Hooks_UseQuery.bs.js";

var Raw = {};

var query = (require("@apollo/client").gql`
  query AllPostsQuery  {
    posts  {
      __typename
      id
      title
      author  {
        __typename
        name
      }
    }
  }
`);

function parse(value) {
  var value$1 = value.posts;
  return {
          posts: value$1.map(function (value) {
                var value$1 = value.author;
                return {
                        __typename: value.__typename,
                        id: value.id,
                        title: value.title,
                        author: !(value$1 == null) ? ({
                              __typename: value$1.__typename,
                              name: value$1.name
                            }) : undefined
                      };
              })
        };
}

function serialize(value) {
  var value$1 = value.posts;
  var posts = value$1.map(function (value) {
        var value$1 = value.author;
        var author;
        if (value$1 !== undefined) {
          var value$2 = value$1.name;
          var value$3 = value$1.__typename;
          author = {
            __typename: value$3,
            name: value$2
          };
        } else {
          author = null;
        }
        var value$4 = value.title;
        var value$5 = value.id;
        var value$6 = value.__typename;
        return {
                __typename: value$6,
                id: value$5,
                title: value$4,
                author: author
              };
      });
  return {
          posts: posts
        };
}

function serializeVariables(param) {
  
}

function makeVariables(param) {
  
}

function makeDefaultVariables(param) {
  
}

var AllPostsQuery_inner = {
  Raw: Raw,
  query: query,
  parse: parse,
  serialize: serialize,
  serializeVariables: serializeVariables,
  makeVariables: makeVariables,
  makeDefaultVariables: makeDefaultVariables
};

var include = ApolloClient__React_Hooks_UseQuery.Extend({
      query: query,
      Raw: Raw,
      parse: parse,
      serialize: serialize,
      serializeVariables: serializeVariables
    });

var use = include.use;

var AllPostsQuery_refetchQueryDescription = include.refetchQueryDescription;

var AllPostsQuery_useLazy = include.useLazy;

var AllPostsQuery_useLazyWithVariables = include.useLazyWithVariables;

var AllPostsQuery = {
  AllPostsQuery_inner: AllPostsQuery_inner,
  Raw: Raw,
  query: query,
  parse: parse,
  serialize: serialize,
  serializeVariables: serializeVariables,
  makeVariables: makeVariables,
  makeDefaultVariables: makeDefaultVariables,
  refetchQueryDescription: AllPostsQuery_refetchQueryDescription,
  use: use,
  useLazy: AllPostsQuery_useLazy,
  useLazyWithVariables: AllPostsQuery_useLazyWithVariables
};

function PostsPage$PostList(Props) {
  var posts = Props.posts;
  return Belt_Array.map(posts, (function (p) {
                return React.createElement(PostPreview$Client.make, {
                            title: p.title,
                            author: Belt_Option.mapWithDefault(p.author, "", (function (a) {
                                    return a.name;
                                  })),
                            key: p.id
                          });
              }));
}

var PostList = {
  make: PostsPage$PostList
};

function PostsPage(Props) {
  var match = Curry.app(use, [
        undefined,
        undefined,
        undefined,
        undefined,
        undefined,
        undefined,
        undefined,
        undefined,
        undefined,
        undefined,
        undefined,
        undefined,
        undefined,
        undefined
      ]);
  var match$1 = match.data;
  if (match.loading) {
    return "Loading...";
  } else if (match$1 !== undefined) {
    return React.createElement(PostsPage$PostList, {
                posts: match$1.posts
              });
  } else if (match.error !== undefined) {
    return "Error :(";
  } else {
    return "lul";
  }
}

var make = PostsPage;

export {
  AllPostsQuery ,
  PostList ,
  make ,
  
}
/* query Not a pure module */
