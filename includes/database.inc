<?php

/**
 * @file
 * Wrapper for database interface code.
 */

/**
 * A hash value to check when outputting database errors, md5('DB_ERROR').
 *
 * @see drupal_error_handler()
 */
define('DB_ERROR', 'a515ac9c2796ca0e23adbe92c68fc9fc');

/**
 * @defgroup database Database abstraction layer
 * @{
 * Allow the use of different database servers using the same code base.
 *
 * Drupal provides a slim database abstraction layer to provide developers with
 * the ability to support multiple database servers easily. The intent of this
 * layer is to preserve the syntax and power of SQL as much as possible, while
 * letting Drupal control the pieces of queries that need to be written
 * differently for different servers and provide basic security checks.
 *
 * Most Drupal database queries are performed by a call to db_query() or
 * db_query_range(). Module authors should also consider using pager_query() for
 * queries that return results that need to be presented on multiple pages, and
 * tablesort_sql() for generating appropriate queries for sortable tables.
 *
 * For example, one might wish to return a list of the most recent 10 nodes
 * authored by a given user. Instead of directly issuing the SQL query
 * @code
 *   SELECT n.nid, n.title, n.created FROM node n WHERE n.uid = $uid LIMIT 0, 10;
 * @endcode
 * one would instead call the Drupal functions:
 * @code
 *   $result = db_query_range('SELECT n.nid, n.title, n.created
 *     FROM {node} n WHERE n.uid = %d', $uid, 0, 10);
 *   while ($node = db_fetch_object($result)) {
 *     // Perform operations on $node->body, etc. here.
 *   }
 * @endcode
 * Curly braces are used around "node" to provide table prefixing via
 * db_prefix_tables(). The explicit use of a user ID is pulled out into an
 * argument passed to db_query() so that SQL injection attacks from user input
 * can be caught and nullified. The LIMIT syntax varies between database servers,
 * so that is abstracted into db_query_range() arguments. Finally, note the
 * common pattern of iterating over the result set using db_fetch_object().
 */

/**
 * Perform an SQL query and return success or failure.
 *
 * @param $sql
 *   A string containing a complete SQL query.  %-substitution
 *   parameters are not supported.
 * @return
 *   An array containing the keys:
 *      success: a boolean indicating whether the query succeeded
 *      query: the SQL query executed, passed through check_plain()
 */
function update_sql($sql) {
  $result = db_query($sql, true);
  return array('success' => $result !== FALSE, 'query' => check_plain($sql));
}

/**
 * MySQL 8 reserved keywords list.
 *
 * @see https://dev.mysql.com/doc/refman/8.0/en/keywords.html
 */
global $db_mysql8_reserved_keywords;
$db_mysql8_reserved_keywords = array(
  'accessible',
  'add',
  'admin',
  'all',
  'alter',
  'analyze',
  'and',
  'as',
  'asc',
  'asensitive',
  'before',
  'between',
  'bigint',
  'binary',
  'blob',
  'both',
  'by',
  'call',
  'cascade',
  'case',
  'change',
  'char',
  'character',
  'check',
  'collate',
  'column',
  'condition',
  'constraint',
  'continue',
  'convert',
  'create',
  'cross',
  'cube',
  'cume_dist',
  'current_date',
  'current_time',
  'current_timestamp',
  'current_user',
  'cursor',
  'database',
  'databases',
  'day_hour',
  'day_microsecond',
  'day_minute',
  'day_second',
  'dec',
  'decimal',
  'declare',
  'default',
  'delayed',
  'delete',
  'dense_rank',
  'desc',
  'describe',
  'deterministic',
  'distinct',
  'distinctrow',
  'div',
  'double',
  'drop',
  'dual',
  'each',
  'else',
  'elseif',
  'empty',
  'enclosed',
  'escaped',
  'except',
  'exists',
  'exit',
  'explain',
  'false',
  'fetch',
  'first_value',
  'float',
  'float4',
  'float8',
  'for',
  'force',
  'foreign',
  'from',
  'fulltext',
  'function',
  'generated',
  'get',
  'grant',
  'group',
  'grouping',
  'groups',
  'having',
  'high_priority',
  'hour_microsecond',
  'hour_minute',
  'hour_second',
  'if',
  'ignore',
  'in',
  'index',
  'infile',
  'inner',
  'inout',
  'insensitive',
  'insert',
  'int',
  'int1',
  'int2',
  'int3',
  'int4',
  'int8',
  'integer',
  'interval',
  'into',
  'io_after_gtids',
  'io_before_gtids',
  'is',
  'iterate',
  'join',
  'json_table',
  'key',
  'keys',
  'kill',
  'lag',
  'last_value',
  'lead',
  'leading',
  'leave',
  'left',
  'like',
  'limit',
  'linear',
  'lines',
  'load',
  'localtime',
  'localtimestamp',
  'lock',
  'long',
  'longblob',
  'longtext',
  'loop',
  'low_priority',
  'master_bind',
  'master_ssl_verify_server_cert',
  'match',
  'maxvalue',
  'mediumblob',
  'mediumint',
  'mediumtext',
  'middleint',
  'minute_microsecond',
  'minute_second',
  'mod',
  'modifies',
  'natural',
  'not',
  'no_write_to_binlog',
  'nth_value',
  'ntile',
  'null',
  'numeric',
  'of',
  'on',
  'optimize',
  'optimizer_costs',
  'option',
  'optionally',
  'or',
  'order',
  'out',
  'outer',
  'outfile',
  'over',
  'partition',
  'percent_rank',
  'persist',
  'persist_only',
  'precision',
  'primary',
  'procedure',
  'purge',
  'range',
  'rank',
  'read',
  'reads',
  'read_write',
  'real',
  'recursive',
  'references',
  'regexp',
  'release',
  'rename',
  'repeat',
  'replace',
  'require',
  'resignal',
  'restrict',
  'return',
  'revoke',
  'right',
  'rlike',
  'row',
  'rows',
  'row_number',
  'schema',
  'schemas',
  'second_microsecond',
  'select',
  'sensitive',
  'separator',
  'set',
  'show',
  'signal',
  'smallint',
  'spatial',
  'specific',
  'sql',
  'sqlexception',
  'sqlstate',
  'sqlwarning',
  'sql_big_result',
  'sql_calc_found_rows',
  'sql_small_result',
  'ssl',
  'starting',
  'stored',
  'straight_join',
  'system',
  'table',
  'terminated',
  'then',
  'tinyblob',
  'tinyint',
  'tinytext',
  'to',
  'trailing',
  'trigger',
  'true',
  'undo',
  'union',
  'unique',
  'unlock',
  'unsigned',
  'update',
  'usage',
  'use',
  'using',
  'utc_date',
  'utc_time',
  'utc_timestamp',
  'values',
  'varbinary',
  'varchar',
  'varcharacter',
  'varying',
  'virtual',
  'when',
  'where',
  'while',
  'window',
  'with',
  'write',
  'xor',
  'year_month',
  'zerofill',
);

/**
 * Checks if we are under certain database driver and database version.
 *
 * For example, to check if we are under MySQL 8.0 or higher use
 * db_version_compare('mysql', '8.0.0').
 *
 * @param string $driver
 *   Database driver name from $db_url setting. For example 'mysql' (which covers both 'mysql:' and 'mysqli:' drivers.
 * @param string $version
 *   Database version returned by db_version() function call.
 * @param string $operator
 *   Operator to compare version. '>=' by default.
 * @return bool
 *   TRUE if version check passes; otherwise FALSE.
*/
function db_version_compare($driver, $version, $operator = '>=') {
  global $db_url, $db_active_name;

  if (is_array($db_url)) {
    $db_active_url = array_key_exists($db_active_name, $db_url) ? $db_url[$db_active_name] : $db_url['default'];
  }
  else {
    $db_active_url = $db_url;
  }

  if (substr($db_active_url, 0, strlen($driver)) === $driver) {
    if (version_compare(db_version(), $version, $operator)) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Append a database prefix to all tables in a query.
 *
 * Queries sent to Drupal should wrap all table names in curly brackets. This
 * function searches for this syntax and adds Drupal's table prefix to all
 * tables, allowing Drupal to coexist with other systems in the same database if
 * necessary.
 *
 * @param $sql
 *   A string containing a partial or entire SQL query.
 * @return
 *   The properly-prefixed string.
 */
function db_prefix_tables($sql) {
  global $db_prefix, $db_mysql8_reserved_keywords;

  // Identify prefix settings to apply.
  if (is_array($db_prefix)) {
    $db_prefix_local = $db_prefix;
    if (array_key_exists('default', $db_prefix)) {
      unset($db_prefix_local['default']);
      $default_replacement = $db_prefix['default'];
    }
    else {
      $default_replacement = '';
    }
  }
  else {
    $db_prefix_local = array();
    $default_replacement = $db_prefix;
  }

  // Add prefixes and transform curly braces into pipes in order to mark already done operations
  // while preserving table name encapsulation for the next step.
  foreach ($db_prefix_local as $table_name => $prefix) {
    $sql = strtr($sql, array('{' . $table_name . '}' => '|' . $prefix . $table_name . '|'));
  }
  $sql = strtr($sql, array('{' => '|' . $default_replacement, '}' => '|'));

  // For MySQL 8, escape table names corersponding to reserved keywords.
  if (db_version_compare('mysql', '8.0.0')) {
    foreach ($db_mysql8_reserved_keywords as $keyword) {
      $sql = str_replace('|' . $keyword . '|', '`' . $keyword . '`', $sql);
    }
  }

  // Remove pipes.
  return str_replace('|', '', $sql);
}

/**
 * Active database connection name.
 */
global $db_active_name;
$db_active_name = FALSE;

/**
 * Activate a database for future queries.
 *
 * If it is necessary to use external databases in a project, this function can
 * be used to change where database queries are sent. If the database has not
 * yet been used, it is initialized using the URL specified for that name in
 * Drupal's configuration file. If this name is not defined, a duplicate of the
 * default connection is made instead.
 *
 * Be sure to change the connection back to the default when done with custom
 * code.
 *
 * @param $name
 *   The key in the $db_url global variable from settings.php. If omitted, the
 *   default connection will be made active.
 *
 * @return
 *   The name of the previously active database, or FALSE if none was found.
 */
function db_set_active($name = 'default') {
  global $db_url, $db_slave_url, $db_type, $active_db, $active_slave_db;
  global $db_active_name;
  static $db_conns, $db_slave_conns;

  if (empty($db_url)) {
    include_once 'includes/install.inc';
    install_goto('install.php');
  }

  if (!isset($db_conns[$name])) {
    // Initiate a new connection, using the named DB URL specified.
    if (is_array($db_url)) {
      $connect_url = array_key_exists($name, $db_url) ? $db_url[$name] : $db_url['default'];
      if (is_array($db_slave_url[$name])) {
        $slave_index = mt_rand(0, count($db_slave_url[$name]) - 1);
        $slave_connect_url = $db_slave_url[$name][$slave_index];
      }
      else {
        $slave_connect_url = $db_slave_url[$name];        
      }
    }
    else {
      $connect_url = $db_url;
      if (is_array($db_slave_url)) {
        $slave_index = mt_rand(0, count($db_slave_url) - 1);
        $slave_connect_url = $db_slave_url[$slave_index];
      }
      else {
        $slave_connect_url = $db_slave_url;        
      }
    }

    $db_type = substr($connect_url, 0, strpos($connect_url, '://'));
    $handler = "./includes/database.$db_type.inc";

    if (is_file($handler)) {
      include_once $handler;
    }
    else {
      _db_error_page("The database type '". $db_type ."' is unsupported. Please use either 'mysql' or 'mysqli' for MySQL, or 'pgsql' for PostgreSQL databases.");
    }

    $db_conns[$name] = db_connect($connect_url);
    if (!empty($slave_connect_url)) {
      $db_slave_conns[$name] = db_connect($slave_connect_url); 
    }
  }

  $previous_name = $db_active_name;
  // Set the active connection.
  $db_active_name = $name;
  $active_db = $db_conns[$name];
  if (isset($db_slave_conns[$name])) {
    $active_slave_db = $db_slave_conns[$name];
  }
  else {
    unset($active_slave_db);
  }

  return $previous_name;
}

/**
 * Helper function to show fatal database errors.
 *
 * Prints a themed maintenance page with the 'Site off-line' text,
 * adding the provided error message in the case of 'display_errors'
 * set to on. Ends the page request; no return.
 *
 * @param $error
 *   The error message to be appended if 'display_errors' is on.
 */
function _db_error_page($error = '') {
  global $db_type;
  drupal_init_language();
  drupal_maintenance_theme();
  drupal_set_header($_SERVER['SERVER_PROTOCOL'] .' 503 Service Unavailable');
  drupal_set_title('Site off-line');

  $message = '<p>The site is currently not available due to technical problems. Please try again later. Thank you for your understanding.</p>';
  $message .= '<hr /><p><small>If you are the maintainer of this site, please check your database settings in the <code>settings.php</code> file and ensure that your hosting provider\'s database server is running. For more help, see the <a href="http://drupal.org/node/258">handbook</a>, or contact your hosting provider.</small></p>';

  if ($error && ini_get('display_errors')) {
    $message .= '<p><small>The '. theme('placeholder', $db_type) .' error was: '. theme('placeholder', $error) .'.</small></p>';
  }

  print theme('maintenance_page', $message);
  exit;
}

/**
 * Returns a boolean depending on the availability of the database.
 */
function db_is_active() {
  global $active_db;
  return !empty($active_db);
}

/**
 * Helper function for db_query().
 */
function _db_query_callback($match, $init = FALSE) {
  static $args = NULL;
  if ($init) {
    $args = $match;
    return;
  }

  switch ($match[1]) {
    case '%d': // We must use type casting to int to convert FALSE/NULL/(TRUE?)
      $value = array_shift($args);
      // Do we need special bigint handling?
      if ($value > PHP_INT_MAX) {
        $precision = ini_get('precision');
        @ini_set('precision', 16);
        $value = sprintf('%.0f', $value);
        @ini_set('precision', $precision);
      }
      else {
        $value = (int) $value;
      }
      // We don't need db_escape_string as numbers are db-safe.
      return $value;
    case '%s':
      return db_escape_string(array_shift($args));
    case '%n':
      // Numeric values have arbitrary precision, so can't be treated as float.
      // is_numeric() allows hex values (0xFF), but they are not valid.
      $value = trim(array_shift($args));
      return is_numeric($value) && !preg_match('/x/i', $value) ? $value : '0';
    case '%%':
      return '%';
    case '%f':
      return (float) array_shift($args);
    case '%b': // binary data
      return db_encode_blob(array_shift($args));
  }
}

/**
 * Generate placeholders for an array of query arguments of a single type.
 *
 * Given a Schema API field type, return correct %-placeholders to
 * embed in a query
 *
 * @param $arguments
 *  An array with at least one element.
 * @param $type
 *   The Schema API type of a field (e.g. 'int', 'text', or 'varchar').
 */
function db_placeholders($arguments, $type = 'int') {
  $placeholder = db_type_placeholder($type);
  return implode(',', array_fill(0, count($arguments), $placeholder));
}

/**
 * Indicates the place holders that should be replaced in _db_query_callback().
 */
define('DB_QUERY_REGEXP', '/(%d|%s|%%|%f|%b|%n)/');

/**
 * Helper function for db_rewrite_sql.
 *
 * Collects JOIN and WHERE statements via hook_db_rewrite_sql()
 * Decides whether to select primary_key or DISTINCT(primary_key)
 *
 * @param $query
 *   Query to be rewritten.
 * @param $primary_table
 *   Name or alias of the table which has the primary key field for this query.
 *   Typical table names would be: {blocks}, {comments}, {forum}, {node},
 *   {menu}, {term_data} or {vocabulary}. However, in most cases the usual
 *   table alias (b, c, f, n, m, t or v) is used instead of the table name.
 * @param $primary_field
 *   Name of the primary field.
 * @param $args
 *   Array of additional arguments.
 * @return
 *   An array: join statements, where statements, field or DISTINCT(field).
 */
function _db_rewrite_sql($query = '', $primary_table = 'n', $primary_field = 'nid', $args = array()) {
  $where = array();
  $join = array();
  $distinct = FALSE;
  foreach (module_implements('db_rewrite_sql') as $module) {
    $result = module_invoke($module, 'db_rewrite_sql', $query, $primary_table, $primary_field, $args);
    if (isset($result) && is_array($result)) {
      if (isset($result['where'])) {
        $where[] = $result['where'];
      }
      if (isset($result['join'])) {
        $join[] = $result['join'];
      }
      if (isset($result['distinct']) && $result['distinct']) {
        $distinct = TRUE;
      }
    }
    elseif (isset($result)) {
      $where[] = $result;
    }
  }

  $where = empty($where) ? '' : '('. implode(') AND (', $where) .')';
  $join = empty($join) ? '' : implode(' ', $join);

  return array($join, $where, $distinct);
}

/**
 * Runs a basic query in the active slave database.
 *
 * User-supplied arguments to the query should be passed in as separate
 * parameters so that they can be properly escaped to avoid SQL injection
 * attacks.
 *
 * @param $query
 *   A string containing an SQL query.
 * @param ...
 *   A variable number of arguments which are substituted into the query
 *   using printf() syntax. Instead of a variable number of query arguments,
 *   you may also pass a single array containing the query arguments.
 *
 *   Valid %-modifiers are: %s, %d, %f, %b (binary data, do not enclose
 *   in '') and %%.
 *
 *   NOTE: using this syntax will cast NULL and FALSE values to decimal 0,
 *   and TRUE values to decimal 1.
 *
 * @return
 *   A database query result resource, or FALSE if the query was not
 *   executed correctly.
 */
function db_query_slave($query) {
  $args = func_get_args();
  array_shift($args);
  $query = db_prefix_tables($query);
  if (isset($args[0]) and is_array($args[0])) { // 'All arguments in one array' syntax
    $args = $args[0];
  }
  _db_query_callback($args, TRUE);
  $query = preg_replace_callback(DB_QUERY_REGEXP, '_db_query_callback', $query);
  return _db_query($query, FALSE, TRUE);
}

/**
 * Rewrites node, taxonomy and comment queries. Use it for listing queries. Do not
 * use FROM table1, table2 syntax, use JOIN instead.
 *
 * @param $query
 *   Query to be rewritten.
 * @param $primary_table
 *   Name or alias of the table which has the primary key field for this query.
 *   Typical table names would be: {blocks}, {comments}, {forum}, {node},
 *   {menu}, {term_data} or {vocabulary}. However, it is more common to use the
 *   the usual table aliases: b, c, f, n, m, t or v.
 * @param $primary_field
 *   Name of the primary field.
 * @param $args
 *   An array of arguments, passed to the implementations of hook_db_rewrite_sql.
 * @return
 *   The original query with JOIN and WHERE statements inserted from
 *   hook_db_rewrite_sql implementations. nid is rewritten if needed.
 */
function db_rewrite_sql($query, $primary_table = 'n', $primary_field = 'nid',  $args = array()) {
  list($join, $where, $distinct) = _db_rewrite_sql($query, $primary_table, $primary_field, $args);

  if ($distinct) {
    $query = db_distinct_field($primary_table, $primary_field, $query);
  }

  if (!empty($where) || !empty($join)) {
    $pattern = '{
      # Beginning of the string
      ^
      ((?P<anonymous_view>
        # Everything within this set of parentheses is named "anonymous view"
        (?:
          [^()]++                   # anything not parentheses
        |
          \( (?P>anonymous_view) \)          # an open parenthesis, more "anonymous view" and finally a close parenthesis.
        )*
      )[^()]+WHERE)
    }x';
    preg_match($pattern, $query, $matches);
    if (!$where) {
      $where = '1 = 1';
    }
    if ($matches) {
      $n = strlen($matches[1]);
      $second_part = substr($query, $n);
      $first_part = substr($matches[1], 0, $n - 5) ." $join WHERE $where AND ( ";
      // PHP 4 does not support strrpos for strings. We emulate it.
      $haystack_reverse = strrev($second_part);
    }
    else {
      $haystack_reverse = strrev($query);
    }
    // No need to use strrev on the needle, we supply GROUP, ORDER, LIMIT
    // reversed.
    foreach (array('PUORG', 'REDRO', 'TIMIL') as $needle_reverse) {
      $pos = strpos($haystack_reverse, $needle_reverse);
      if ($pos !== FALSE) {
        // All needles are five characters long.
        $pos += 5;
        break;
      }
    }
    if ($matches) {
      if ($pos === FALSE) {
        $query = $first_part . $second_part .')';
      }
      else {
        $query = $first_part . substr($second_part, 0, -$pos) .')'. substr($second_part, -$pos);
      }
    }
    elseif ($pos === FALSE) {
      $query .= " $join WHERE $where";
    }
    else {
      $query = substr($query, 0, -$pos) . " $join WHERE $where " . substr($query, -$pos);
    }
  }

  return $query;
}

/**
 * Adds the DISTINCT flag to the supplied query and returns the altered query.
 *
 * The supplied query should not contain a DISTINCT flag. This will not, and
 * never did guarantee that you will obtain distinct values of $table.$field.
 *
 * @param $table
 *   Unused. Kept to retain API compatibility.
 * @param $field
 *   Unused. Kept to retain API compatibility.
 * @param $query
 *   Query to which the DISTINCT flag should be applied.
 *
 * @return
 *   SQL query with the DISTINCT flag set.
 */
function db_distinct_field($table, $field, $query) {
  $matches = array();
  if (!preg_match('/^SELECT\s*DISTINCT/i', $query, $matches)) {
    // Only add distinct to the outer SELECT to avoid messing up subqueries.
    $query = preg_replace('/^SELECT/i', 'SELECT DISTINCT', $query);
  }

  return $query;
}

/**
 * Restrict a dynamic table, column or constraint name to safe characters.
 *
 * Only keeps alphanumeric and underscores.
 */
function db_escape_table($string) {
  return preg_replace('/[^A-Za-z0-9_]+/', '', $string);
}

/**
 * @} End of "defgroup database".
 */

/**
 * @defgroup schemaapi Schema API
 * @{
 *
 * A Drupal schema definition is an array structure representing one or
 * more tables and their related keys and indexes. A schema is defined by
 * hook_schema(), which usually lives in a modulename.install file.
 *
 * By implementing hook_schema() and specifying the tables your module
 * declares, you can easily create and drop these tables on all
 * supported database engines. You don't have to deal with the
 * different SQL dialects for table creation and alteration of the
 * supported database engines.
 *
 * hook_schema() should return an array with a key for each table that
 * the module defines.
 *
 * The following keys are defined:
 *
 *   - 'description': A string describing this table and its purpose.
 *     References to other tables should be enclosed in
 *     curly-brackets.  For example, the node_revisions table
 *     description field might contain "Stores per-revision title and
 *     body data for each {node}."
 *   - 'fields': An associative array ('fieldname' => specification)
 *     that describes the table's database columns.  The specification
 *     is also an array.  The following specification parameters are defined:
 *     - 'description': A string describing this field and its purpose.
 *       References to other tables should be enclosed in
 *       curly-brackets.  For example, the node table vid field
 *       description might contain "Always holds the largest (most
 *       recent) {node_revisions}.vid value for this nid."
 *     - 'type': The generic datatype: 'varchar', 'int', 'serial'
 *       'float', 'numeric', 'text', 'blob' or 'datetime'.  Most types
 *       just map to the according database engine specific
 *       datatypes.  Use 'serial' for auto incrementing fields. This
 *       will expand to 'int auto_increment' on mysql.
 *     - 'serialize': A boolean indicating whether the field will be stored
         as a serialized string.
 *     - 'size': The data size: 'tiny', 'small', 'medium', 'normal',
 *       'big'.  This is a hint about the largest value the field will
 *       store and determines which of the database engine specific
 *       datatypes will be used (e.g. on MySQL, TINYINT vs. INT vs. BIGINT).
 *       'normal', the default, selects the base type (e.g. on MySQL,
 *       INT, VARCHAR, BLOB, etc.).
 *       Not all sizes are available for all data types. See
 *       db_type_map() for possible combinations.
 *     - 'not null': If true, no NULL values will be allowed in this
 *       database column.  Defaults to false.
 *     - 'default': The field's default value.  The PHP type of the
 *       value matters: '', '0', and 0 are all different.  If you
 *       specify '0' as the default value for a type 'int' field it
 *       will not work because '0' is a string containing the
 *       character "zero", not an integer.
 *     - 'length': The maximal length of a type 'char', 'varchar' or 'text'
 *       field.  Ignored for other field types.
 *     - 'unsigned': A boolean indicating whether a type 'int', 'float'
 *       and 'numeric' only is signed or unsigned.  Defaults to
 *       FALSE.  Ignored for other field types.
 *     - 'precision', 'scale': For type 'numeric' fields, indicates
 *       the precision (total number of significant digits) and scale
 *       (decimal digits right of the decimal point).  Both values are
 *       mandatory.  Ignored for other field types.
 *     All parameters apart from 'type' are optional except that type
 *     'numeric' columns must specify 'precision' and 'scale'.
 *  - 'primary key': An array of one or more key column specifiers (see below)
 *    that form the primary key.
 *  - 'unique keys': An associative array of unique keys ('keyname' =>
 *    specification).  Each specification is an array of one or more
 *    key column specifiers (see below) that form a unique key on the table.
 *  - 'indexes':  An associative array of indexes ('indexame' =>
 *    specification).  Each specification is an array of one or more
 *    key column specifiers (see below) that form an index on the
 *    table.
 *
 * A key column specifier is either a string naming a column or an
 * array of two elements, column name and length, specifying a prefix
 * of the named column.
 *
 * As an example, here is a SUBSET of the schema definition for
 * Drupal's 'node' table.  It show four fields (nid, vid, type, and
 * title), the primary key on field 'nid', a unique key named 'vid' on
 * field 'vid', and two indexes, one named 'nid' on field 'nid' and
 * one named 'node_title_type' on the field 'title' and the first four
 * bytes of the field 'type':
 *
 * @code
 * $schema['node'] = array(
 *   'fields' => array(
 *     'nid'      => array('type' => 'serial', 'unsigned' => TRUE, 'not null' => TRUE),
 *     'vid'      => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'default' => 0),
 *     'type'     => array('type' => 'varchar', 'length' => 32, 'not null' => TRUE, 'default' => ''),
 *     'title'    => array('type' => 'varchar', 'length' => 128, 'not null' => TRUE, 'default' => ''),
 *   ),
 *   'primary key' => array('nid'),
 *   'unique keys' => array(
 *     'vid'     => array('vid')
 *   ),
 *   'indexes' => array(
 *     'nid'                 => array('nid'),
 *     'node_title_type'     => array('title', array('type', 4)),
 *   ),
 * );
 * @endcode
 *
 * @see drupal_install_schema()
 */

 /**
 * Create a new table from a Drupal table definition.
 *
 * @param $ret
 *   Array to which query results will be added.
 * @param $name
 *   The name of the table to create.
 * @param $table
 *   A Schema API table definition array.
 */
function db_create_table(&$ret, $name, $table) {
  $statements = db_create_table_sql($name, $table);
  foreach ($statements as $statement) {
    $ret[] = update_sql($statement);
  }
}

/**
 * Return an array of field names from an array of key/index column specifiers.
 *
 * This is usually an identity function but if a key/index uses a column prefix
 * specification, this function extracts just the name.
 *
 * @param $fields
 *   An array of key/index column specifiers.
 * @return
 *   An array of field names.
 */
function db_field_names($fields) {
  $ret = array();
  foreach ($fields as $field) {
    if (is_array($field)) {
      $ret[] = $field[0];
    }
    else {
      $ret[] = $field;
    }
  }
  return $ret;
}

/**
 * Given a Schema API field type, return the correct %-placeholder.
 *
 * Embed the placeholder in a query to be passed to db_query and and pass as an
 * argument to db_query a value of the specified type.
 *
 * @param $type
 *   The Schema API type of a field.
 * @return
 *   The placeholder string to embed in a query for that type.
 */
function db_type_placeholder($type) {
  switch ($type) {
    case 'varchar':
    case 'char':
    case 'text':
    case 'datetime':
      return "'%s'";

    case 'numeric':
      // Numeric values are arbitrary precision numbers.  Syntacically, numerics
      // should be specified directly in SQL. However, without single quotes
      // the %s placeholder does not protect against non-numeric characters such
      // as spaces which would expose us to SQL injection.
      return '%n';

    case 'serial':
    case 'int':
      return '%d';

    case 'float':
      return '%f';

    case 'blob':
      return '%b';
  }

  // There is no safe value to return here, so return something that
  // will cause the query to fail.
  return 'unsupported type '. $type .'for db_type_placeholder';
}

/**
 * @} End of "defgroup schemaapi".
 */

/**
 * Sets a session variable specifying the lag time for ignoring a slave server.
 * Backport of D7 functionality.
 */
function db_ignore_slave() {
  global $active_slave_db;

  // Only set ignore_slave_server if there are slave servers being used, which
  // is assumed db_url is an array.
  if (isset($active_slave_db)) {
    // Five minutes is long enough to allow the slave to break and resume
    // interrupted replication without causing problems on the Drupal site from
    // the old data.
    $duration = variable_get('maximum_replication_lag', 300);
    // Set session variable with amount of time to delay before using slave.
    // This will stick around for 5 minutes by default. 
    // There is another $_Session variable 'not_slavesafe' for single queries.
    $_SESSION['ignore_slave_server'] = $_SERVER['REQUEST_TIME'] + $duration;
  }
}
